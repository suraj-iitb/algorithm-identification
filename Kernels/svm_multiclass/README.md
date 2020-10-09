Training:
    ./svm_multiclass_learn -c 5000 ../Data/multi_class/train.dat ../Models/multi_class.model


Testing:
    ./svm_multiclass_classify ../Data/multi_class/test.dat ../Models/multi_class.model ../Prediction/multi_class.pred