from transformers import AutoModelForSequenceClassification, AutoTokenizer, AutoConfig
from transformers_interpret import SequenceClassificationExplainer

config = AutoConfig.from_pretrained("models/java")
model = AutoModelForSequenceClassification.from_pretrained("models/java")
tokenizer = AutoTokenizer.from_pretrained("models/java")

cls_explainer = SequenceClassificationExplainer("void bubbleSort(int arr[], int n) { int i, j; for (i = 0; i < n-1; i++) for (j = 0; j < n-i-1; j++) if (arr[j] > arr[j+1]) swap(&arr[j], &arr[j+1]); }", model, tokenizer)
attributions = cls_explainer()

print(attributions.word_attributions)
cls_explainer.visualize("example.html")
