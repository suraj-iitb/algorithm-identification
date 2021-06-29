lang=java #fine-tuning a language-specific model for each programming language 
pretrained_model=microsoft/codebert-base  #Roberta: roberta-base

python run_classifier.py \
--model_type roberta \
--task_name codesearch \
--do_train \
--train_file train.txt \
--max_seq_length 200 \
--per_gpu_train_batch_size 16 \
--per_gpu_eval_batch_size 16 \
--learning_rate 1e-5 \
--num_train_epochs 8 \
--gradient_accumulation_steps 1 \
--overwrite_output_dir \
--data_dir ../../data/codesearch/train_valid/$lang \
--output_dir ./models/$lang  \
--model_name_or_path $pretrained_model
