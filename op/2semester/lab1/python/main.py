from module import *

def main():
    file_name = input('Enter file name : ')
    content = get_input() 
    writitng_mode = get_writing_mode()
    write_file(file_name, writitng_mode, content)
    export_data(file_name)
    show_file_content(file_name, 'Initial Text Data : ')
    show_file_content(file_name[:-4] + '_exp.txt', 'Processed Text Data : ')
    
main()