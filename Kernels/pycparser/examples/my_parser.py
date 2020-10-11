from __future__ import print_function
import argparse
import sys
import os

def show(node, buf=sys.stdout):

    l = len(node.children())
    # current node
    node_name = node.__class__.__name__
    if node_name != 'Typedef':
        buf.write(node_name)
        if l != 0:
            buf.write(' (')
        
        count = 0
        # its children
        for (child_name, child) in node.children():
            count  += 1
            if child.__class__.__name__ != 'Typedef':
                show(child, buf)

                if count != l:
                    buf.write(',')

        if l != 0:
            buf.write(')')

sys.path.extend(['.', '..'])
from pycparser import c_parser, c_ast, parse_file

if __name__ == "__main__":
    # argparser = argparse.ArgumentParser('Dump AST')
    # argparser.add_argument('filename', help='name of file to parse')
    # args = argparser.parse_args()

    f = open('../Data/AST/data-b-i.train', 'w')
    for name in ['Bubble', 'Insertion']:
        directory = '../../MOSS/Data/' + name +'/Dump/C/'
        dir = os.listdir(directory)
        
        for file in dir:
            # print(os.path.join(directory, file))
            if not file.endswith('.txt'):
                ast = parse_file(os.path.join(directory, file), use_cpp=True, cpp_path='gcc', cpp_args=['-E', r'-Iutils/fake_libc_include'])
                if name == 'Bubble':
                    f.write('1 ')
                else:
                    f.write('-1 ')
                f.write('|BT| (')
                show(ast, f)
                f.write(') |ET|\n')
