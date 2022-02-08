from module import *

def main():
    file_name = input('Enter file name (.txt only):')
    content = get_input()
    print('Entered text: ')
    print(content)

    mode = input('Write or extend file? W/E : ')

    save_file(file_name, content, 'w' if mode == 'W' else 'a')

    export_data(file_name)
    print('Content of', file_name[:-4]+'_exp.txt', '(text changed as asked in the task) :')
    print(get_file_cont(file_name[:-4]+'_exp.txt'))


main()