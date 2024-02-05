#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

const string P1_WINS = "Player 1 Wins!";
const string P2_WINS = "Player 2 Wins!";
const string TIE = "Tie!";

string string_upper(string s);
int score_word(string s, char p1[], char p2[], char p3[], char p4[], char p5[], char p8[], char p10[]);
int find_char(char target_c, char c_arr[], int point_val);

int main(int argc, string argv[])
{
    char points_1[10] = {
        'A', 'E', 'I', 'L', 'N', 'O', 'R', 'S', 'T', 'U',
    };
    char points_2[2] = {
        'D',
        'G',
    };
    char points_3[4] = {
        'B',
        'C',
        'M',
        'P',
    };
    char points_4[5] = {
        'F', 'H', 'V', 'W', 'Y',
    };
    char points_5[1] = {
        'K',
    };
    char points_8[2] = {
        'J',
        'X',
    };
    char points_10[2] = {
        'Q',
        'Z',
    };

    string p1_word = get_string("Player 1: ");
    string p2_word = get_string("Player 2: ");
    p1_word = string_upper(p1_word);
    p2_word = string_upper(p2_word);

    int p1_score = score_word(p1_word, points_1, points_2, points_3, points_4, points_5, points_8, points_10);
    int p2_score = score_word(p2_word, points_1, points_2, points_3, points_4, points_5, points_8, points_10);

    if (p1_score > p2_score)
    {
        printf("%s\n", P1_WINS);
    }
    else if (p1_score < p2_score)
    {
        printf("%s\n", P2_WINS);
    }
    else
    {
        printf("%s\n", TIE);
    };
}

string string_upper(string s)
{
    for (int i = 0, s_len = strlen(s); i < s_len; i++)
    {
        s[i] = toupper(s[i]);
    }

    return s;
}

int score_word(string word, char p1[], char p2[], char p3[], char p4[], char p5[], char p8[], char p10[])
{
    int word_score = 0;
    for (int i = 0, s_len = strlen(word); i < s_len; i++)
    {
        int score_1 = find_char(word[i], p1, 1);
        if (score_1 != 0)
        {
            word_score += 1;
            continue;
        };

        int score_2 = find_char(word[i], p2, 2);
        if (score_2 != 0)
        {
            word_score += 2;
            continue;
        };

        int score_3 = find_char(word[i], p3, 3);
        if (score_3 != 0)
        {
            word_score += 3;
            continue;
        };

        int score_4 = find_char(word[i], p4, 4);
        if (score_4 != 0)
        {
            word_score += 4;
            continue;
        };

        int score_5 = find_char(word[i], p5, 5);
        if (score_5 != 0)
        {
            word_score += 5;
            continue;
        };

        int score_8 = find_char(word[i], p8, 8);
        if (score_8 != 0)
        {
            word_score += 8;
            continue;
        };

        int score_10 = find_char(word[i], p10, 10);
        if (score_10 != 0)
        {
            word_score += 10;
            continue;
        };
    }
    return word_score;
}

int find_char(char target_c, char c_arr[], int point_val)
{
    int i = 0;
    char curr_c = 'a';
    while (curr_c != '\0')
    {
        if (c_arr[i] == target_c)
        {
            return point_val;
        }
        curr_c = c_arr[i];
        i++;
    }
    return 0;
}
