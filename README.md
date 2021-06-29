# Algorithm Identification in Source Code of Programming Assignments

Design a system which takes source code which is known to carry out a given functionality (e.g. sorting) as input, and identify algorithm used among a known set of algorithms for this functionality as output.

There are various approaches which we have explored for this problem which is mentioned below:
1. Using Execution Information
    1. Memory usage information
    2. Time taken information
2. Using MOSS (Measure of Software Similarity)
3. Using Kernel SVM   
    1. Tree kernel
    2. Graph kernel
4. Using pre-trained deep learning models (from microsoft)
    1. CodeBERT
    2. GraphCodeBERT

## Steps to run

### Execution Information (All paths are relative to MTP/Execution/)
**Requirements**: valgrind, matplotlib

**Note**: See code and change parameters like path etc.


    1. Put the code you want to analyze into `Code` folder
    2. Compile it using following command:
        $ gcc <filename> -o <output_filename>
    3. Generate input to code using script `gen-input.py` in `Input` folder
    4. For runtime info for each algorithm independently over multiple runs:
        1. Get runtime info
            $ bash time.sh
        2. Preprocess runtime dump info
            $ python preprocess.py
        3. Generate plots for each algorithm seperately
            $ python plot.py
    5. For runtime info combined for all algorithms along with CI/SD:
        1. Get runtime info
            $ bash time.sh
        2. Preprocess runtime dump info
            $ python preprocess.py
        3. Generate plots only
            $ python plot.py
        4. Gnerate stats (CI/SD) using
            $ python stats.py
        4. Generate plots along with CI/SD
            $ python error-plot.py
    6. For memory info
        1. Get memory dump using
            $ bash memory.sh
        2. Parse the memory dump
            $ python parser.py
        3. Generate plots only
            $ python plot.py
        4. Gnerate stats (CI/SD) using
            $ python stats.py
        4. Generate plots along with CI/SD
            $ python error-plot.py

### MOSS (All paths are relative to MTP/MOSS/)
**Requirements**: mosspy, requests

**Note**: See code and change parameters like path etc.

    1. Crawl id's of the codes
        $ python crawl-id.py
    2. Crawl codes
        $ python crawler.py
    3. Run MOSS script
        $ python plag.py
    4. Change working directory
        $ cd Hypothesis/All
    5. Parse html output of moss
        $ python html-parser.py
    6. Find max, min, and average similarity of codes for each algorithm
        $ python max-avg.py
    7. Run all hypothesis which we formulated
        $ python hypothesis.py
    8. Generate score for each code wrt all algorithms
        $ python score-gen.py
    9. Perform prediction and calculate precision, recall scores
        $ python pred.py

### Tree Kernel (All paths are relative to MTP/Tree-Kernels/)
**Requirements**: sklearn

**Note**: See code and change parameters like path etc.

    1. Generate AST
        $ cd pycparser
        $ python examples/my_parser.py

    2. Split data into train and test splits
        $ cd ../data/AST   (for different types of algorithm path may vary)
        $ python data-gen.py
    3. Training of the model
        $ cd ../../svm-light-TK-1.5
        $ python learn.py
    4. Perform prediction on unseen data and calculate metrics like precision and recall
        $ python classify.py
        $ python multi-class.py
        $ python metrics.py
    
### Graph-Kernels Kernel (All paths are relative to MTP/Graph-Kernels/)
**Requirements**: 
    
1. See requirements.txt file
2. GraKel (Manual installation from https://github.com/ysig/GraKeL)
3. joern-cli (https://docs.joern.io/installation/)
4. graph-easy (http://manpages.ubuntu.com/manpages/artful/man1/graph-easy.1p.html)

**Note**: See code and change parameters like path etc.

    1. Generate CFG
        $ python cfg-generator.py
    2. Open `Jupyter` notebook directly or using anaconda 
    3. Run all cells of the notebook for each type of algorithm (Each notebook splits data, train, test and calculate metrics like  precision and recall)
        1. gk.ipynb: Sorting algos
        2. gk-searching.ipynb: Searching algos
        3. gk-path.ipynb: Shortest path algos



### CodeBERT (All paths are relative to MTP/BERT)
**Requirements**: 
    
1. See requirements.txt file
2. GPU is a must

**Note**: See code and change parameters like path, language etc.

    1. Crawl the dataset (Run once for each algorithm by changing the parameters like problem id and language by looking at AIZU online judge at https://judge.u-aizu.ac.jp/onlinejudge/finder.jsp?course=ALDS1)
        $ python crawl-id.py
        $ python crawler.py
    
    2. Generate dataset in the format required by the model (see code and specify `no` parameter which denotes multiples of these examples will go into test set)
        1. tok_split.py: For sorting algorithm
        2. split_search.py: For searching algorithm
        3. path_split.py: For shortest path algorithm

        Note: It will generate 2 files  batc_c_<no>.txt and train_c_<no>.txt
    
    3. Copy these files into folder required by the models
        $ cp train_c_<no>.txt data/codesearch/train_valid/java/train.txt
        $ cp batch_c_<no>.txt data/codesearch/test/java/batch_0.txt
    
    4. Change the working directory
        $ cd CodeBERT/codesearch
    
    5. Train the model (change paramters in `run.sh` if required)
        $ bash run.sh
    
    6. Test the model (change paramters in `pred.sh` if required)
        $ bash pred.sh

    Note: It will also generate metrics like precision and recall scores.

### GraphCodeBERT (All paths are relative to MTP/BERT)
**Requirements**: 
    
1. See requirements.txt file
2. GPU is a must

**Note**: See code and change parameters like path, language etc.

    1. Crawl the dataset if not done already (Run once for each algorithm by changing the parameters like problem id and language by looking at AIZU online judge at https://judge.u-aizu.ac.jp/onlinejudge/finder.jsp?course=ALDS1)
        $ python crawl-id.py
        $ python crawler.py

    2. Parsing module is already built and put as `my-languages.so` file in GraphCodeBERT/clonedetection/parser folder (If not then need to build from scratch using documentation at https://tree-sitter.github.io/tree-sitter/creating-parsers#installation)

    3. Generate dataset in the format required by the model (see code and specify `no` parameter which denotes multiples of these examples will go into test set)
        1. GraphCodeBERT/clonedetection/data_split.py: For sorting algorithm
        2. GraphCodeBERT/clonedetection/data_split_search.py: For searching algorithm
        3. GraphCodeBERT/clonedetection/data_split_path.py: For shortest path algorithm

        Note: It will generate  files  4 files data.txt, train.txt, test.txt and valid.txt.

    4. Copy these files into folder required by the models
        $ cp *.txt dataset/

    5. Chnage the working directory
        $ cd GraphCodeBERT/clonedetection/
    
    6. Train the model (change paramters in `run.sh` if required)
        $ bash run.sh
    
    7. Test the model (change paramters in `pred.sh` if required)
        $ bash pred.sh

    Note: It will also generate metrics like precision and recall scores.


## Model Interpretrebility
We have explored 2 model explainability methods (these methods works at exmaple level):
1. LIME (Code in CodeBERT/codesearch/lime.py): Provide the code in text variable
2. Integrated Gradients (Code in CodeBERT/codesearch/explain.py): Provide the code in text variable

## Few common pitfalls:
1. While crawling data if network error occurs then restart crawling from that point onwards (It is very frequent error while crawling data). 
2. While running moss, sometimes when we are in IITB network we are unable to contact moss server so make sure to use mobile network.
3. While running CodeBERT and GraphCodeBERT on server always login into internet.iitb.ac.in as it downloads models, tokenizer and config files from huggingface library.


