#include<iostream>
#include<cstdlib>

using namespace std;

enum enAnswer { Rhigt = 1, Wrong = 2, };
enum enLevelQuestionsChoice { Easy = 1, Med = 2, Hard = 3, Mix1 = 4 };
enum enOperationType { Add = 1, Sup = 2, Mul = 3, div1 = 4, Mix2 = 5 };


struct stQuestionInfo
{
    short NumberQuestions = 0;          // Round number.
    enLevelQuestionsChoice PlayerChoiceLevel;
    enOperationType OperationTypeChoise;
    enAnswer Answer;
    string WinnerName;
};
struct stGameResults
{
    short NumberQuestions = 0;
    short PlayerRhigtTimes = 0;
    short PlayerWrongTimes = 0;
    enOperationType OperationType;
    enLevelQuestionsChoice QuestionLevel;
    enAnswer GameRuselt;         // Stores the overall game Ruselts.
};

int RandomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}
string ChoiceNameQuestionLevel(enLevelQuestionsChoice Choice)
{
    string arrGameChoices[4] = { "Easy", "Med", "Hard" , "Mix" };
    return arrGameChoices[Choice - 1];
}
string ChoiceNameOperation(enOperationType Choice)
{
    string arrGameChoices[5] = { "Add", "Sub", "Mul" , "Div","Mix" };
    return arrGameChoices[Choice - 1];
}
short GetComputerChoiceOperation()
{
    return RandomNumber(1, 4);
}
short GetComputerChoiceLevel()
{
    return RandomNumber(1, 3);
}



void SetWinnerScreenColor(enAnswer Answer)
{
    switch (Answer)
    {
    case enAnswer::Rhigt:
        system("color 2F"); // turn screen to Green
        break;

    case enAnswer::Wrong:
        system("color 4F"); // turn screen to Red
        cout << "\a";       // يصدر صوت تنبيه (Bell) عند خسارة اللاعب
        break;
    }
}


enAnswer ISWonTheGame(short PlayerRhigtTimes, short PlayerWrongTimes)
{
    if (PlayerRhigtTimes > PlayerWrongTimes) return enAnswer::Rhigt;
    else if (PlayerWrongTimes > PlayerRhigtTimes) return enAnswer::Wrong;

}

void QuestionCorrect(enAnswer Answer)
{

    if (Answer == enAnswer::Rhigt)
    {
        cout << "Rhigt Answer : -)";
        SetWinnerScreenColor(Answer);
    }
    else
    {
        SetWinnerScreenColor(Answer);
    }

}
enAnswer AddFunctionLevel(int From, int To)
{
    short Answer;
    short Number1 = RandomNumber(From, To);
    short Number2 = RandomNumber(From, To);
    cout << Number1 << "\n" << Number2 << " +";
    cout << "\n____________\n";
    cin >> Answer;

    if (Answer == Number1 + Number2)
    {
        return enAnswer::Rhigt;
    }
    else
    {
        cout << "Wrong Answer : -(";
        cout << "\nThe Rhigt Answer is : " << Number1 + Number2;
        return enAnswer::Wrong;
    }

}
enAnswer SubFunctionLevel(int From, int To)
{
    short Answer;
    short Number1 = RandomNumber(From, To);
    short Number2 = RandomNumber(From, To);
    cout << Number1 << "\n" << Number2 << " -";
    cout << "\n____________\n";
    cin >> Answer;

    if (Answer == Number1 - Number2)
    {
        return enAnswer::Rhigt;
    }
    else
    {
        cout << "Wrong Answer : -(";
        cout << "\nThe Rhigt Answer is : " << Number1 - Number2;
        return enAnswer::Wrong;
    }

}
enAnswer MulFunctionLevel(int From, int To)
{
    short Answer;
    short Number1 = RandomNumber(From, To);
    short Number2 = RandomNumber(From, To);
    cout << Number1 << "\n" << Number2 << " *";
    cout << "\n____________\n";
    cin >> Answer;

    if (Answer == Number1 * Number2)
    {
        return enAnswer::Rhigt;
    }
    else
    {
        cout << "Wrong Answer : -(";
        cout << "\nThe Rhigt Answer is : " << Number1 * Number2;
        return enAnswer::Wrong;
    }

}
enAnswer DivFunctionLevel(int From, int To)
{
    short Answer;
    short Number1 = RandomNumber(From, To);
    short Number2 = RandomNumber(From, To);
    cout << Number1 << "\n" << Number2 << " /";
    cout << "\n____________\n";
    cin >> Answer;

    if (Answer == Number1 / Number2)
    {
        return enAnswer::Rhigt;
    }
    else
    {
        cout << "Wrong Answer : -(";
        cout << "\nThe Rhigt Answer is : " << Number1 / Number2;
        return enAnswer::Wrong;
    }

}
enAnswer MixFunctionLevel(int From, int To)
{
    enAnswer Answer;
    short MixOperation = GetComputerChoiceOperation();

    switch (MixOperation)
    {

    case 1:
        Answer = AddFunctionLevel(From, To);
        return Answer;
        break;
    case 2:
        Answer = SubFunctionLevel(From, To);
        return Answer;
        break;
    case 3:
        Answer = MulFunctionLevel(From, To);
        return Answer;
        break;
    case 4:
        Answer = DivFunctionLevel(From, To);
        return Answer;
        break;

    }

}

enAnswer AddFunction(stQuestionInfo QuestionInfo)
{
    short MixLevel = GetComputerChoiceLevel();

    switch (QuestionInfo.PlayerChoiceLevel)
    {
    case enLevelQuestionsChoice::Mix1:
        switch (MixLevel)
        {
        case 1:
            QuestionInfo.Answer = AddFunctionLevel(1, 10);
            return QuestionInfo.Answer;
            break;
        case 2:
            QuestionInfo.Answer = AddFunctionLevel(1, 50);
            return QuestionInfo.Answer;
            break;
        case 3:
            QuestionInfo.Answer = AddFunctionLevel(1, 100);
            return QuestionInfo.Answer;
            break;

        }
    case enLevelQuestionsChoice::Easy:
        QuestionInfo.Answer = AddFunctionLevel(1, 10);
        return QuestionInfo.Answer;
        break;
    case enLevelQuestionsChoice::Med:
        QuestionInfo.Answer = AddFunctionLevel(1, 50);
        return QuestionInfo.Answer;
        break;
    case enLevelQuestionsChoice::Hard:
        QuestionInfo.Answer = AddFunctionLevel(50, 100);
        return QuestionInfo.Answer;
        break;

    }

}
enAnswer SubFunction(stQuestionInfo QuestionInfo)
{
    short MixLevel = GetComputerChoiceLevel();

    switch (QuestionInfo.PlayerChoiceLevel)
    {
    case enLevelQuestionsChoice::Mix1:
        switch (MixLevel)
        {
        case 1:
            QuestionInfo.Answer = SubFunctionLevel(1, 10);
            return QuestionInfo.Answer;
            break;
        case 2:
            QuestionInfo.Answer = SubFunctionLevel(1, 50);
            return QuestionInfo.Answer;
            break;
        case 3:
            QuestionInfo.Answer = SubFunctionLevel(1, 100);
            return QuestionInfo.Answer;
            break;

        }
    case enLevelQuestionsChoice::Easy:
        QuestionInfo.Answer = SubFunctionLevel(1, 10);
        return QuestionInfo.Answer;
        break;
    case enLevelQuestionsChoice::Med:
        QuestionInfo.Answer = SubFunctionLevel(1, 50);
        return QuestionInfo.Answer;
        break;
    case enLevelQuestionsChoice::Hard:
        QuestionInfo.Answer = SubFunctionLevel(50, 100);
        return QuestionInfo.Answer;
        break;
    }

}
enAnswer MulFunction(stQuestionInfo QuestionInfo)
{
    short MixLevel = GetComputerChoiceLevel();

    switch (QuestionInfo.PlayerChoiceLevel)
    {
    case enLevelQuestionsChoice::Mix1:
        switch (MixLevel)
        {
        case 1:
            QuestionInfo.Answer = MulFunctionLevel(1, 10);
            return QuestionInfo.Answer;
            break;
        case 2:
            QuestionInfo.Answer = MulFunctionLevel(1, 50);
            return QuestionInfo.Answer;
            break;
        case 3:
            QuestionInfo.Answer = MulFunctionLevel(1, 100);
            return QuestionInfo.Answer;
            break;

        }
    case enLevelQuestionsChoice::Easy:
        QuestionInfo.Answer = MulFunctionLevel(1, 10);
        return QuestionInfo.Answer;
        break;
    case enLevelQuestionsChoice::Med:
        QuestionInfo.Answer = MulFunctionLevel(1, 50);
        return QuestionInfo.Answer;
        break;
    case enLevelQuestionsChoice::Hard:
        QuestionInfo.Answer = MulFunctionLevel(50, 100);
        return QuestionInfo.Answer;
        break;

    }

}
enAnswer DivFunction(stQuestionInfo QuestionInfo)
{
    short MixLevel = GetComputerChoiceLevel();

    switch (QuestionInfo.PlayerChoiceLevel)
    {
    case enLevelQuestionsChoice::Mix1:
        switch (MixLevel)
        {
        case 1:
            QuestionInfo.Answer = DivFunctionLevel(1, 10);
            return QuestionInfo.Answer;
            break;
        case 2:
            QuestionInfo.Answer = DivFunctionLevel(1, 50);
            return QuestionInfo.Answer;
            break;
        case 3:
            QuestionInfo.Answer = DivFunctionLevel(1, 100);
            return QuestionInfo.Answer;
            break;

        }

    case enLevelQuestionsChoice::Easy:
        QuestionInfo.Answer = DivFunctionLevel(1, 10);
        return QuestionInfo.Answer;
        break;
    case enLevelQuestionsChoice::Med:
        QuestionInfo.Answer = DivFunctionLevel(1, 50);
        return QuestionInfo.Answer;
        break;
    case enLevelQuestionsChoice::Hard:
        QuestionInfo.Answer = DivFunctionLevel(50, 100);
        return QuestionInfo.Answer;
        break;
    }

}
enAnswer MixFunction(stQuestionInfo QuestionInfo)
{
    short MixLevel = GetComputerChoiceLevel();
    switch (QuestionInfo.PlayerChoiceLevel)
    {
    case enLevelQuestionsChoice::Mix1:
        switch (MixLevel)
        {
        case 1:
            QuestionInfo.Answer = MixFunctionLevel(1, 10);
            return QuestionInfo.Answer;
            break;
        case 2:
            QuestionInfo.Answer = MixFunctionLevel(1, 50);
            return QuestionInfo.Answer;
            break;
        case 3:
            QuestionInfo.Answer = MixFunctionLevel(1, 100);
            return QuestionInfo.Answer;
            break;

        }
    case enLevelQuestionsChoice::Easy:
        QuestionInfo.Answer = MixFunctionLevel(1, 10);
        return QuestionInfo.Answer;
        break;
    case enLevelQuestionsChoice::Med:
        QuestionInfo.Answer = MixFunctionLevel(1, 50);
        return QuestionInfo.Answer;
        break;
    case enLevelQuestionsChoice::Hard:
        QuestionInfo.Answer = MixFunctionLevel(50, 100);
        return QuestionInfo.Answer;
        break;

    }


}



stGameResults FillGameRuselts(int NumberQuestion, short PlayerRhigtTimes, short PlayerWrongTimes, enLevelQuestionsChoice PlayerChoice, enOperationType OperationType)
{
    stGameResults GameResults;

    GameResults.NumberQuestions = NumberQuestion;
    GameResults.PlayerRhigtTimes = PlayerRhigtTimes;
    GameResults.PlayerWrongTimes = PlayerWrongTimes;
    GameResults.QuestionLevel = PlayerChoice;
    GameResults.OperationType = OperationType;
    GameResults.GameRuselt = ISWonTheGame(PlayerRhigtTimes, PlayerWrongTimes);


    return GameResults;
}

enLevelQuestionsChoice ReadLevelQuestions()
{
    short Choice;
    do
    {
        cout << "\nEnter Questions Level : [1]:Easy, [2]:Med, [3]:Hard, [4]:Mix  ? ";
        cin >> Choice;
    } while (Choice < 1 || Choice > 4);
    return (enLevelQuestionsChoice)Choice;
}
enOperationType ReadOperationType()
{
    short Choice;
    do
    {
        cout << "\nEnter Operation Type : [1]:Add, [2]:Sup, [3]:Mul, [4]:div, [5]:Mix  ? ";
        cin >> Choice;
    } while (Choice < 1 || Choice > 5);
    return (enOperationType)Choice;
}

enAnswer GoToQuestion(stQuestionInfo QuestionInfo)
{


    switch (QuestionInfo.OperationTypeChoise)
    {
    case enOperationType::Add:
        QuestionInfo.Answer = AddFunction(QuestionInfo);
        return QuestionInfo.Answer;
        break;
    case enOperationType::Sup:
        QuestionInfo.Answer = SubFunction(QuestionInfo);
        return QuestionInfo.Answer;
        break;
    case enOperationType::Mul:
        QuestionInfo.Answer = MulFunction(QuestionInfo);
        return QuestionInfo.Answer;
        break;
    case enOperationType::div1:
        QuestionInfo.Answer = DivFunction(QuestionInfo);
        return QuestionInfo.Answer;
        break;
    case enOperationType::Mix2:
        QuestionInfo.Answer = MixFunction(QuestionInfo);
        return QuestionInfo.Answer;
        break;

    }


}

stGameResults PlayGame(short HowManyQuestions)
{
    stQuestionInfo QuestionInfo;
    short PlayerRhigtTimes = 0, PlayerWrongTimes = 0;

    QuestionInfo.PlayerChoiceLevel = ReadLevelQuestions();
    QuestionInfo.OperationTypeChoise = ReadOperationType();
    for (short QuestionNumber = 1; QuestionNumber <= HowManyQuestions; QuestionNumber++)
    {
        cout << "\n\nQuestion [" << QuestionNumber << "/" << HowManyQuestions << "]\n\n";
        QuestionInfo.NumberQuestions = QuestionNumber;
        QuestionInfo.Answer = GoToQuestion(QuestionInfo);
        QuestionCorrect(QuestionInfo.Answer);

        if (QuestionInfo.Answer == enAnswer::Rhigt)
            PlayerRhigtTimes++;
        else if (QuestionInfo.Answer == enAnswer::Wrong)
            PlayerWrongTimes++;

    }

    return FillGameRuselts(HowManyQuestions, PlayerRhigtTimes, PlayerWrongTimes, QuestionInfo.PlayerChoiceLevel, QuestionInfo.OperationTypeChoise);

}
string PASSOrFAILD(enAnswer Ruselts)
{
    if (Ruselts == enAnswer::Rhigt)
    {
        return " PASS : -)";
    }
    else
    {
        return " FAILD : -(";
    }
}


void ShowGameOverScreen(stGameResults GameResults)
{
    cout << "\n\n_____________________________________________________\n\n";
    cout << "Final Results is " << PASSOrFAILD(GameResults.GameRuselt);
    cout << "\n_____________________________________________________\n\n";
}


void ShowFinalGameResults(stGameResults GameResults)
{

    cout << "Number of Questions        : " << GameResults.NumberQuestions << endl;
    cout << "Question level             : " << ChoiceNameQuestionLevel(GameResults.QuestionLevel) << endl;
    cout << "OpType                     : " << ChoiceNameOperation(GameResults.OperationType) << endl;
    cout << "Number of Rhigt Answer     : " << GameResults.PlayerRhigtTimes << endl;
    cout << "Number of Wrong Answer     : " << GameResults.PlayerWrongTimes << endl;
    cout << "_____________________________________________________\n";

    SetWinnerScreenColor(GameResults.GameRuselt);
}

short ReadHowManyQuestions()
{


    short NumberQuestions;

    cout << "How Many Questions do you want to answer ? ";
    cin >> NumberQuestions;

    return NumberQuestions;
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
        stGameResults GameResults = PlayGame(ReadHowManyQuestions());
        ShowGameOverScreen(GameResults);
        ShowFinalGameResults(GameResults);

        cout << endl << "\nDo you want to play again? (Y/N): ";
        cin >> PlayAgain;

    } while (PlayAgain == 'Y' || PlayAgain == 'y');
}
int main()
{

    srand((unsigned)time(NULL));  // Seed random number generator.
    StartGame();
    return 0;
}