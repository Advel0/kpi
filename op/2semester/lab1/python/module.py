def get_input():
    print('Write your text ( to end enter Ctrl + X ): ')
    content = ''
    line = input()
    while line != '\x18':
        content += line + '\n'
        line = input()
    return content

def write_file(_file_name , _wm,  _content):
    with open(_file_name, _wm) as file:
        file.write(_content)

def get_writing_mode():
    inp = input('Please chose a writing mode ( W - rewrite/write | E - extend) : ')
    if inp == 'W':
        mode = 'w'
    elif inp == 'E':
        mode = 'a'
    else:
        mode = 'w'
        print('Incorrent mode, writing mode set to default (Write file)')
    return mode

def export_data(file_name):
    with open(file_name , 'r') as file, open(file_name[:-4]+'_exp.txt', 'w') as file_exp:
        for line in file.readlines():
            file_exp.write(line[:-1] + line.split()[0][-1] +'\n')


def show_file_content(_file_name, _message):
    print(_message)
    with open(_file_name, 'r') as file:
        print(file.read())
