
#include <iostream>
using namespace std;

enum enOperationType { Add = 1, Sub = 2, Mult = 3, Div = 4, MixOp = 5 };
enum  enQuestionsLevel { EasyLevel = 1, MedLevel = 2, HardLevel = 3, Mix = 4 };

struct stQuestion
{
    int Number1 = 0;
    int Number2 = 0;
    enOperationType OperationType;
    enQuestionsLevel QuestionLevel;
    int CorrectAnswer = 0;
    int PlayerAnswer = 0;
    bool AnswerResult = false;
};

struct stQuizz
{
    stQuestion QuestionList[100];
    short NumberOfQuestions;
    enQuestionsLevel QuestionsLevel;
    enOperationType OpType;
    short NumberOfWrongAnswers = 0;
    short NumberOfRightAnswers = 0;
    bool isPass = false;
};
int RandomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}
enOperationType GetRandomOperationType()
{
    return (enOperationType)RandomNumber(1, 4);
}
int SimpleCalculator(int Number1, int Number2, enOperationType OpType)
{
    switch (OpType)
    {
    case enOperationType::Add:
        return Number1 + Number2;
    case enOperationType::Sub:
        return Number1 - Number2;
    case enOperationType::Mult:
        return Number1 * Number2;
    case enOperationType::Div:
        return (Number2 != 0) ? (Number1 / Number2) : 0;  // Avoid division by zero.
    default:
        return Number1 + Number2;
    }
}
stQuestion GenerateQuestion(enQuestionsLevel QuestionLevel, enOperationType OpType)
{
    stQuestion Question;

    if (QuestionLevel == enQuestionsLevel::Mix)
        QuestionLevel = (enQuestionsLevel)RandomNumber(1, 3);

    if (OpType == enOperationType::MixOp)
        OpType = GetRandomOperationType();

    Question.OperationType = OpType;

    switch (QuestionLevel)
    {
    case enQuestionsLevel::EasyLevel:
        Question.Number1 = RandomNumber(1, 10);
        Question.Number2 = RandomNumber(1, 10);
        break;
    case enQuestionsLevel::MedLevel:
        Question.Number1 = RandomNumber(10, 50);
        Question.Number2 = RandomNumber(10, 50);
        break;
    case enQuestionsLevel::HardLevel:
        Question.Number1 = RandomNumber(50, 100);
        Question.Number2 = RandomNumber(50, 100);
        break;
    }

    Question.CorrectAnswer = SimpleCalculator(Question.Number1, Question.Number2, Question.OperationType);
    Question.QuestionLevel = QuestionLevel;

    return Question;
}
void  GenerateQuizzQuestion(stQuizz& Quizz)
{

    for (short Question = 0; Question < Quizz.NumberOfQuestions; Question++)
    {
        Quizz.QuestionList[Question] = GenerateQuestion(Quizz.QuestionsLevel, Quizz.OpType);
    }
}

short ReadHowManyQuestions()
{


    short NumberQuestions;
    do
    {


        cout << "How Many Questions do you want to answer ? ";
        cin >> NumberQuestions;
    } while (NumberQuestions < 1 || NumberQuestions > 10);

    return NumberQuestions;
}
enQuestionsLevel ReadQuestionsLevel()
{


    short QuestionsLevel;
    do
    {
        cout << "\nEnter Questions Level : [1]:Easy, [2]:Med, [3]:Hard, [4]:Mix  ? ";
        cin >> QuestionsLevel;
    } while (QuestionsLevel < 1 || QuestionsLevel > 4);

    return enQuestionsLevel(QuestionsLevel);
}
enOperationType ReadOpType()
{
    short OpType;
    do
    {
        cout << "\nEnter Operation Type : [1]:Add, [2]:Sup, [3]:Mul, [4]:div, [5]:Mix  ? ";
        cin >> OpType;
    } while (OpType < 1 || OpType > 5);
    return (enOperationType)OpType;
}
string GetOpTypeSymbol(enOperationType OpType)
{
    switch (OpType)
    {
    case enOperationType::Add:
        return "+";
    case enOperationType::Sub:
        return "-";
    case enOperationType::Mult:
        return "x";
    case enOperationType::Div:
        return "/";
    default:
        return "Mix";
    }
}
string GetQuestionLevelText(enQuestionsLevel QuestionLevel)
{
    string arrQuestionLevelText[4] = { "Easy", "Med", "Hard", "Mix" };
    return arrQuestionLevelText[QuestionLevel - 1];
}
void PrintTheQuestion(stQuizz& Quizz, short QuestionNumber)
{
    cout << "\n";
    cout << "Question [" << QuestionNumber + 1 << "/" << Quizz.NumberOfQuestions << "] \n\n";
    cout << Quizz.QuestionList[QuestionNumber].Number1 << endl;
    cout << Quizz.QuestionList[QuestionNumber].Number2 << " ";
    cout << GetOpTypeSymbol(Quizz.QuestionList[QuestionNumber].OperationType);
    cout << "\n__________" << endl;
}
int ReadQuestionAnswer()
{
    int Answer = 0;
    cin >> Answer;
    return Answer;
}
void SetScreenColor(bool Right)
{
    if (Right)
        system("color 2F"); // Green for correct answers.
    else
    {
        system("color 4F"); // Red for incorrect answers.
        cout << "\a"; // Plays an alert sound.
    }
}
void CorrectTheQuestionAnswer(stQuizz& Quizz, short QuestionNumber)
{


    if (Quizz.QuestionList[QuestionNumber].PlayerAnswer != Quizz.QuestionList[QuestionNumber].CorrectAnswer)
    {
        Quizz.QuestionList[QuestionNumber].AnswerResult = false;
        Quizz.NumberOfWrongAnswers++;

        cout << "Wrong Answer :-( \n";
        cout << "The right answer is: ";
        cout << Quizz.QuestionList[QuestionNumber].CorrectAnswer;
        cout << "\n";
    }
    else
    {
        Quizz.QuestionList[QuestionNumber].AnswerResult = true;
        Quizz.NumberOfRightAnswers++;

        cout << "Right Answer :-) \n";
    }

    cout << endl;
    SetScreenColor(Quizz.QuestionList[QuestionNumber].AnswerResult);
}
void AskAndCorrectQuestionListAnswers(stQuizz& Quizz)
{
    for (short QuestionNumber = 0; QuestionNumber < Quizz.NumberOfQuestions; QuestionNumber++)
    {
        PrintTheQuestion(Quizz, QuestionNumber);

        Quizz.QuestionList[QuestionNumber].PlayerAnswer = ReadQuestionAnswer();

        CorrectTheQuestionAnswer(Quizz, QuestionNumber);


    }

    Quizz.isPass = (Quizz.NumberOfRightAnswers >= Quizz.NumberOfWrongAnswers);

}
string GetFinalResultsText(bool Pass)
{
    if (Pass)
        return "PASS:-)";
    else
        return "Fail:-(";

}
void PrintQuizzResults(stQuizz Quizz)
{
    cout << "\n";
    cout << "___________________________________\n\n";

    cout << " Final Results is " << GetFinalResultsText(Quizz.isPass);
    cout << "\n___________________________________\n\n";

    cout << "Number of Questions: " << Quizz.NumberOfQuestions << endl;
    cout << "Questions Level    : " << GetQuestionLevelText(Quizz.QuestionsLevel) << endl;
    cout << "OpType             : " << GetOpTypeSymbol(Quizz.OpType) << endl;
    cout << "Number of Right Answers: " << Quizz.NumberOfRightAnswers << endl;
    cout << "Number of Wrong Answers: " << Quizz.NumberOfWrongAnswers << endl;

    cout << "___________________________________\n";
}
void PlayMathGame()
{
    stQuizz Quizz;
    Quizz.NumberOfQuestions = ReadHowManyQuestions();  // Set a fixed number of questions.
    Quizz.QuestionsLevel = ReadQuestionsLevel();
    Quizz.OpType = ReadOpType();

    GenerateQuizzQuestion(Quizz);
    AskAndCorrectQuestionListAnswers(Quizz);
    PrintQuizzResults(Quizz);


}
void ResetScreen()
{
    system("cls");
    system("color 0F");
}

void StartGame()
{
    char PlayAgain = 'Y';

    do
    {
        ResetScreen();
        PlayMathGame();


        cout << endl << "\nDo you want to play again? (Y/N): ";
        cin >> PlayAgain;

    } while (PlayAgain == 'Y' || PlayAgain == 'y');
}

int main()
{
        srand((unsigned)time(NULL)); 
    StartGame();
    return 0;
}