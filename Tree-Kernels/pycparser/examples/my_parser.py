from __future__ import print_function
import argparse
import sys
import os

def show(node, buf=sys.stdout):

    l = len(node.children())
    # current node
    node_name = node.__class__.__name__
    if node_name != 'Typedef':
        buf.write(' ('+node_name)
        # if l != 0:
        #     buf.write(' (')
        
        count = 0
        # its children
        for (child_name, child) in node.children():
            count  += 1
            if child.__class__.__name__ != 'Typedef':
                show(child, buf)

                # if count != l:
                #     buf.write(' ')

        # if l != 0:
        buf.write(')')

sys.path.extend(['.', '..'])
from pycparser import c_parser, c_ast, parse_file

if __name__ == "__main__":
    # argparser = argparse.ArgumentParser('Dump AST')
    # argparser.add_argument('filename', help='name of file to parse')
    # args = argparser.parse_args()

    for name in ['Insertion', 'Selection', 'Counting', 'Merge', 'Quick']:
        algo = name.lower()
        f = open('../Data1/AST/'+algo+'.ast', 'w')
        directory = '/home/suraj/Data_Dump/' + name +'/C/Code/'
        dir = os.listdir(directory)
        
        for file in dir:
            print(os.path.join(directory, file))
            if not file.endswith('.txt'):
                try:
                    ast = parse_file(os.path.join(directory, file), use_cpp=True, cpp_path='gcc', cpp_args=['-E', r'-Iutils/fake_libc_include'])
                except Exception as e:
                    print(e)
                # if name == 'Bubble':
                #     f.write('1 ')
                # else:
                #     f.write('-1 ')
                f.write(algo +' |BT|')
                show(ast, f)
                f.write(' |ET|\n')
