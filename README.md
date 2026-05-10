# Hackdavis 2026

## Inspiration
The original idea came from Declan, whose mother is a neuropsychologist and had previously mentioned how helpful a similar tool would be for her work.  
In neuropsychology, testing is used to evaluate a patient's brain function. In some cases where brain function is severely deficient in a particular area, a patient's results can reflect random chance. This project aims to allow for a more nuanced and accurate understanding of whether a result could be achieved randomly, so as to allow for better understanding of results such as those from neuropsychological testing.

## What it does
The program allows a user to generate and save tests, and to calculate the likelihood of getting a given score on a test.

## How we built it
The entire project was coded in c++, with a Makefile to automatically compile files and run tests. Gtest was used to create unit tests, making sure that the probability calculations were acurate.

## Challenges we ran into
Early on, we made the decision to implement the project in c++, as we both have lots of experience in the language. However, multiple hours into the project, when it was too late to pivot, we realized that was a somewhat poor choice of language, and we likely should have gone with Python. On the frontend, Python is very good at processing and displaying strings, while in c++, cout is famously clunky to use. On the Backend, Python dynamically allocates space for integers within RAM, meaning there is no maximum size, while c++ has a maximum integer size of 64 bits, which becomes a serious limitation in scale when the program includes calculating the binomial coefficient. Additionally, Python includes the Decimal data type, which would allow for full precision on decimal values, as opposed to the rounding of c++ doubles.

## Accomplishments that we're proud of
Having a working final product by the end of the Hackathon

## What we learned
TODO

## What's next for Score Probability Calculator
Allowing it to calculate the score distribution for tests with two correct answers, with potentially even more flexibility in the future!