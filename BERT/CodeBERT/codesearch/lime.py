import lime
import torch
import torch.nn.functional as F
from lime.lime_text import LimeTextExplainer

from transformers import AutoTokenizer, AutoModelForSequenceClassification

# filename_model = 'ProsusAI/finbert'
filename_model = 'models/java'
tokenizer = AutoTokenizer.from_pretrained(filename_model)
model = AutoModelForSequenceClassification.from_pretrained(filename_model)
class_names = ['0','1', '2', '3', '4', '5']

def predictor(texts):
    device = torch.device("cuda")
    model.to(device)
    input = tokenizer(texts, return_tensors="pt", padding=True)
    input.to(device)
    outputs = model(**input)
    tensor_logits = outputs[0]
    probas = F.softmax(tensor_logits.cpu()).detach().numpy()
    return probas

text = "void bubbleSort(int arr[], int n) { int i, j; for (i = 0; i < n-1; i++) for (j = 0; j < n-i-1; j++) if (arr[j] > arr[j+1]) swap(&arr[j], &arr[j+1]); }"

print(tokenizer(text, return_tensors='pt', padding=True))

explainer = LimeTextExplainer(class_names=class_names)
exp = explainer.explain_instance(text, predictor, num_features=20, num_samples=100, labels=(0, 1, 2, 3, 4, 5))
# exp = explainer.explain_instance(text, predictor, num_features=20, num_samples=200, labels=(0,1,2))
# exp.show_in_notebook(text=text)
# exp.show_in_notebook(text=text, labels=(0,))
exp.save_to_file('op.html')
