#include <iostream>
#include <string>
#include <random>

bool is_valid(std::string value)
{
    return (value == "Rock" || value == "Paper" || value == "Scissors");
}

std::string get_computer_option()
{
    std::random_device rd;
    std::mt19937 gen{rd()};

    switch (gen() % 3)
    {
    case 0:
        return "Rock";
    case 1:
        return "Paper";
    default:
        return "Scissors";
    }
}

std::string get_user_option(std::string option)
{
    if (option == "1" || option == "rock" || option == "Rock")
    {
        return "Rock";
    }
    else if (option == "2" || option == "paper" || option == "Paper")
    {
        return "Paper";
    }
    else if (option == "3" || option == "scissors" || option == "Scissors")
    {
        return "Scissors";
    }
    else
    {
        return option;
    }
}

std::string winner(std::string name)
{
    return "Winner: " + name + ".";
}

int main()
{
    using namespace std;

    bool play = true;

    cout << "Welcome to Rock, Paper, Scissors!\n\nChoose your move:\n1 - Rock,\n2 - Paper,\n3 - Scissors:\n";

    string name = "", option = "";
    size_t rounds{}, user_wins{}, computer_wins{};

    cin >> name;
    cin >> rounds;

    cout << "\nGame Start!\n";

    for (size_t i = 0; i < rounds; i++)
    {
        cin >> option;

        string user_option = get_user_option(option);

        if (!is_valid(user_option))
        {
            cout << "Invalid move. Please enter Rock, Paper, or Scissors.\n";
            return 0;
        }

        string computer_option = get_computer_option(), winner_name = "";
        bool winner_exists = true;

        if (user_option == computer_option)
        {
            // cout << "It's a draw.\n";
            winner_exists = false;
        }
        else if (computer_option == "Rock")
        {
            if (user_option == "Paper")
            {
                user_wins++;
                winner_name = winner(name);
            }
            else
            {
                computer_wins++;
                winner_name = winner("Computer");
            }
        }
        else if (computer_option == "Paper")
        {
            if (user_option == "Rock")
            {
                computer_wins++;
                winner_name = winner("Computer");
            }
            else
            {
                user_wins++;
                winner_name = winner(name);
            }
        }
        else
        {
            if (user_option == "Paper")
            {
                computer_wins++;
                winner_name = winner("Computer");
            }
            else
            {
                user_wins++;
                winner_name = winner(name);
            }
        }

        if (winner_exists)
        {
            cout << "Round " << (i + 1) << ": Computer chose " << computer_option << ", "
                 << name << " chose " << user_option << ". "
                 << winner_name << "\n";
        }
        else
        {
            i--;
        }
    }

    cout << "\nGame Over!\n";
    cout << "Total Score - " << name << ": " << user_wins << ", Computer: " << computer_wins << std::endl;
    cout << "Would you like to play again? (yes/no)\n";

    return 0;
}
