Training:
    ./svm_learn -t 5 -C T ../Data/TK1.2-ARG0vsARG1/arg0.train ../Models/predicate.model

Testing:
    ./svm_classify ../Data/TK1.2-ARG0vsARG1/arg0.test ../Models/predicate.model