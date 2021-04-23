u_string = input('Enter input string: \n')
while u_string != 'q':
    while not ',' in u_string:
        print('Error: No comma in string.')
        u_string = input('Enter input string: \n')
        if u_string == 'q':
            break
        else:
            continue
    if u_string == 'q':
        break
    u_string = u_string.replace(' ', '')
    u_sep = u_string.split(',')
    print('First word:',u_sep[0])
    print('Second word:', u_sep[1])
    print('')
    print('')
    u_string = input('Enter input string: \n')
    