import ast
import pickle
from collections import defaultdict

def main():
    print ('Loading pickle file')
    
    with open('../crawler/pickled-data/algorithms_python3.pkl', 'rb') as file_handler:
        data_source = pickle.load(file_handler)
    print ('Pickle load finished')

    node_counts = defaultdict(int)
    new_samples = []

    for item in data_source:
        root = item['tree']
        new_samples.append(
            {
                'node': _name(root),
                'parent': None,
                'children': [_name(x) for x in ast.iter_child_nodes(root)]
            }
        )
        gen_samples = lambda x: new_samples.extend(_create_samples(x))
        _traverse_tree(root, gen_samples)
    print ('Dumping sample')

    with open('../crawler/pickled-data/algorithms_nodes_python3.pkl', 'wb') as file_handler:
        pickle.dump(new_samples, file_handler)
        file_handler.close()
    print('Samples Len:',len(new_samples))

def _create_samples(node):
    """Convert a node's children into a sample points."""
    samples = []
    for child in ast.iter_child_nodes(node):
        sample = {
            "node": _name(child),
            "parent": _name(node),
            "children": [_name(x) for x in ast.iter_child_nodes(child)]
        }
        samples.append(sample)

    return samples

def _traverse_tree(tree, callback):
    """Traverse a tree and execute the callback on every node."""
    queue = [tree]
    while queue:
        current_node = queue.pop(0)
        children = list(ast.iter_child_nodes(current_node))
        queue.extend(children)
        callback(current_node)

def _name(node):
    """Get the name of a node."""
    return type(node).__name__

main()