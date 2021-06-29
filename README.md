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