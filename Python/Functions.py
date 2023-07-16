def say_helloworld():
    print("Hello world!")


def echo(word):
    for i in range(3): # len(list) could be used to loop over a list instead
        print(word)


input_word = input("Enter a word to echo! > ")
echo(input_word)
