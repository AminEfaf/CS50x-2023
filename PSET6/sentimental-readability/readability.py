text = input("Text :")

lettweCount = 0

for i in text:
    if i.isalpha():
        lettweCount += 1

sentenceCount = 0

for i in text:
    if i == "." or i == "?" or i == "!":
        sentenceCount += 1

index = round(
    0.0588 * (100 * (lettweCount / len(text.split())))
    - 0.296 * (100 * (sentenceCount / len(text.split())))
    - 15.8
)

if index < 1:
    print("Before Grade 1")
elif index >= 16:
    print("Grade 16+")
else:
    print("Grade", index)
