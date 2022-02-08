def export_data(file_name):
    file = open(file_name, 'r')

    file_exp = open(file_name[:-4]+'_exp.txt', 'w')

    for line in file:

        file_exp.write(line[:-1] + line.split()[0][-1] +'\n')

def save_file(file_name, content, mode):
    file = open(file_name, mode)
    file.write(content)


def get_input():
    inp = ''
    print('Enter your text (:q to end):')
    line = input()
    while line != ':q':
        inp += line + '\n'
        line = input()
    return inp

def get_file_cont(file_name):
    file = open(file_name, 'r')
    return file.read()
