from collections import defaultdict
import sys
import os
import ast
import pickle

def build_tree(script):
    """Builds an AST from a script."""
    return ast.parse(script)

if len(sys.argv) !=2:
    print('Usage: python create_ast.py <language>')
    exit(1)
language = sys.argv[1]

result = []
label_counts = defaultdict(int)

with open('algorithms.txt', 'r') as f:
    algos = f.readlines()
    for algo in algos[1:]:
        algo = algo.strip().split(',')
        algorithm = algo[2]
        print('-------------------------------------------------------------------------')
        print(algorithm, language)
        print('-------------------------------------------------------------------------')

        directory = os.path.join('data', algorithm, language)
        id_file = os.path.join(directory, algorithm + '_ids_' + language + '.txt')

        with open(id_file, 'r') as ids:
            for id in ids:
                id = id.strip()
                if id != '':
                    code_file  = os.path.join(directory, algorithm + id + '.py')
                    print('Converting to AST: ', code_file)
                    with open(code_file, 'r') as c:
                        try:
                            result.append({
                                'tree': build_tree(c.read()), 'metadata': {'label': algorithm}
                            })
                            label_counts[algorithm] += 1
                        except Exception as err:
                            print(err)
                        

    print('=======================================================================')
    print('Label counts:', label_counts)
    print('Result size:',len(result))

    print('Dumping scripts')

    output_dir = 'pickled-data'
    if not os.path.exists(output_dir):
        os.makedirs(output_dir)
    outfile = os.path.join(output_dir, 'algorithms_'+ language + '.pkl')

    with open(outfile, 'wb') as f:
        pickle.dump(result, f)
