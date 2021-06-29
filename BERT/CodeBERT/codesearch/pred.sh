lang=java #programming language
idx=0 #test batch idx

python run_classifier.py \
--model_type roberta \
--model_name_or_path microsoft/codebert-base \
--task_name codesearch \
--do_predict \
--output_dir ../../data/codesearch/test/$lang \
--data_dir ../../data/codesearch/test/$lang \
--max_seq_length 200 \
--per_gpu_train_batch_size 16 \
--per_gpu_eval_batch_size 16 \
--learning_rate 1e-5 \
--num_train_epochs 8 \
--test_file batch_${idx}.txt \
--pred_model_dir ./models/$lang \
--test_result_dir ./results/$lang/${idx}_batch_result.txt
