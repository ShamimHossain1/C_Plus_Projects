#include <iostream>

using namespace std;

int main()
{
    int playQuiz(void);
    char playAgain;
play:
    int finalResult = playQuiz();
    cout << "Your final score is: " << finalResult << endl;
    if (finalResult >= 6)
    {
        cout << "You passed the quiz"<<endl;
        cout << "Do you want to play the quiz again?" << endl;
        cout << "press y or n" << endl;
        cin >> playAgain;

        if (playAgain == 'y' || playAgain == 'Y')
        {
            goto play;
        }
        else
        {
            cout << "Thanks for playing the quiz" << endl;
        }
    }
    else
    {
        cout << "You failed the quiz"<<endl;
        cout << "Do you want to play the quiz again?" << endl;
        cout << "press y or n" << endl;
        cin >> playAgain;

        if (playAgain == 'y' || playAgain == 'Y')
        {
            goto play;
        }
        else
        {
            cout << "Thanks for playing the quiz" << endl;
        }
    }
    return 0;
}

int playQuiz()
{

    cout << "---------------------------------------------------" << endl;
    cout << "-------------Welcome To Quiz Game-----------------" << endl;
    cout << "---------------------------------------------------" << endl;

    cout << "---------------------------------------------------" << endl;
    cout << "---------Please follow the blew instructions-------" << endl;
    cout << endl;
    cout << "Step 1: Quiz contains total 10 questions" << endl;
    cout << "Step 2: Each question has 4 options" << endl;
    cout << "Step 3: You have to choose the correct option" << endl;
    cout << "Step 4: You have to choose from A, B, C, D" << endl;
    cout << "Step 4: You will get 1 point for each correct answer" << endl;
    cout << "Step 5: You will get 0 point for each incorrect answer" << endl;
    cout << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "-------------Let's Start The Quiz------------------" << endl;
    cout << "---------Please press S to start the quiz----------" << endl;
    cout << endl;
playInside:
    char c, answer;
    int score = 0;
    cin >> c;
    if (c == 's' || c == 'S')
    {

        cout << "Q1: What is the name of our planet?" << endl;
        cout << "A) Mars" << endl;
        cout << "B) Earth" << endl;
        cout << "C) Venus" << endl;
        cout << "D) Jupiter" << endl;
        cin >> answer;
        if (answer == 'B' || answer == 'b')
        {
            score = score + 1;
        }
        else
        {
            score = score + 0;
        }

        cout << "Q2: How many legs does a spider have?" << endl;
        cout << "A) 4" << endl;
        cout << "B) 6" << endl;
        cout << "C) 8" << endl;
        cout << "D) 10" << endl;
        cin >> answer;
        if (answer == 'C' || answer == 'c')
        {
            score = score + 1;
        }
        else
        {
            score = score + 0;
        }

        cout << "Q3: What color is the sky on a clear day?" << endl;
        cout << "A) Blue" << endl;
        cout << "B) Green" << endl;
        cout << "C) Yellow" << endl;
        cout << "D) Red" << endl;
        cin >> answer;
        if (answer == 'A' || answer == 'a')
        {
            score = score + 1;
        }
        else
        {
            score = score + 0;
        }

        cout << "Q4: What is 5 + 3?" << endl;
        cout << "A) 6" << endl;
        cout << "B) 7" << endl;
        cout << "C) 8" << endl;
        cout << "D) 9" << endl;
        cin >> answer;
        if (answer == 'C' || answer == 'c')
        {
            score = score + 1;
        }
        else
        {
            score = score + 0;
        }

        cout << "Q5: Which animal is known as the king of the jungle?" << endl;
        cout << "A) Tiger" << endl;
        cout << "B) Elephant" << endl;
        cout << "C) Lion" << endl;
        cout << "D) Bear" << endl;
        cin >> answer;
        if (answer == 'C' || answer == 'c')
        {
            score = score + 1;
        }
        else
        {
            score = score + 0;
        }

        cout << "Q6: How many days are there in a week?" << endl;
        cout << "A) 5" << endl;
        cout << "B) 6" << endl;
        cout << "C) 7" << endl;
        cout << "D) 8" << endl;
        cin >> answer;
        if (answer == 'C' || answer == 'c')
        {
            score = score + 1;
        }
        else
        {
            score = score + 0;
        }

        cout << "Q7: What is the color of a ripe banana?" << endl;
        cout << "A) Green" << endl;
        cout << "B) Yellow" << endl;
        cout << "C) Red" << endl;
        cout << "D) Blue" << endl;
        cin >> answer;
        if (answer == 'B' || answer == 'b')
        {
            score = score + 1;
        }
        else
        {
            score = score + 0;
        }

        cout << "Q8: What do bees make?" << endl;
        cout << "A) Milk" << endl;
        cout << "B) Honey" << endl;
        cout << "C) Butter" << endl;
        cout << "D) Bread" << endl;
        cin >> answer;
        if (answer == 'B' || answer == 'b')
        {
            score = score + 1;
        }
        else
        {
            score = score + 0;
        }

        cout << "Q9: What is the largest planet in our solar system?" << endl;
        cout << "A) Mars" << endl;
        cout << "B) Venus" << endl;
        cout << "C) Jupiter" << endl;
        cout << "D) Saturn" << endl;
        cin >> answer;
        if (answer == 'C' || answer == 'c')
        {
            score = score + 1;
        }
        else
        {
            score = score + 0;
        }

        cout << "Q10: What is the shape of a ball?" << endl;
        cout << "A) Square" << endl;
        cout << "B) Triangle" << endl;
        cout << "C) Circle" << endl;
        cout << "D) Rectangle" << endl;
        cin >> answer;
        if (answer == 'C' || answer == 'c')
        {
            score = score + 1;
        }
        else
        {
            score = score + 0;
        }
    }
    else
    {
        cout << "Invalid choice. Please enter S to start." << endl;
        goto playInside;
    }

    return score;
}