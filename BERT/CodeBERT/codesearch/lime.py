import numpy as np
import lime
import torch
import torch.nn.functional as F
from lime.lime_text import LimeTextExplainer

from transformers import AutoTokenizer, AutoModelForSequenceClassification

filename_model = 'ProsusAI/finbert'
tokenizer = AutoTokenizer.from_pretrained(filename_model)
model = AutoModelForSequenceClassification.from_pretrained(filename_model)
class_names = ['positive','negative', 'neutral']

def predictor(texts):
    device = torch.device("cuda")
    model.to(device)
    input = tokenizer(texts, return_tensors="pt", padding=True)
    input.to(device)
    outputs = model(**input)
    tensor_logits = outputs[0]
    probas = F.softmax(tensor_logits.cpu()).detach().numpy()
    return probas

text = '''void sort(int a[],int s)'''
print(tokenizer(text, return_tensors='pt', padding=True))

explainer = LimeTextExplainer(class_names=class_names)
exp = explainer.explain_instance(text, predictor, num_features=20, num_samples=200)
exp.show_in_notebook(text=text)