import re


def main():

    text = input("Text: ")
    
    letters = count_letters(text)
    words = count_words(text)
    sentences = count_sentences(text)
    
    l = (letters / words) * 100
    s = (sentences / words) * 100
    
    count = 0.0588 * l - 0.296 * s - 15.8
    
    if count < 1:
        print("Before Grade 1")
    elif count > 16:
        print("Grade 16+")
    else:
        print("Grade {}".format(round(count)))
        

def count_letters(s):
    
    return len(re.findall(r'\w', s))
    
    # sum = 0
    # for i in range(len(s)):
    #     if s[i].isalpha():
    #         sum += 1
    # return sum
    

def count_words(s):
    return len(re.findall(r'\s', s))+1
    
    # sum = 1
    # for i in range(len(s)):
    #     if s[i].isspace():
    #         sum += 1
    # return sum

    
def count_sentences(s):
    return len(re.findall(r'[.|?|!]', s))
    
    # sum = 0
    # for i in range(len(s)):
    #     if (s[i] == '?') or (s[i] == '.') or (s[i] == '!'):
    #         sum += 1
    # return sum
    

main()