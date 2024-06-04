#include <iostream>
#include <vector>
#include <string>

using namespace std;

enum TokenType
{
    // Single-character tokens.
    LEFT_PAREN,
    RIGHT_PAREN,
    LEFT_BRACE,
    RIGHT_BRACE,
    COMMA,
    DOT,
    MINUS,
    PLUS,
    SEMICOLON,
    SLASH,
    STAR,

    // One or two character tokens.
    BANG,
    BANG_EQUAL,
    EQUAL,
    EQUAL_EQUAL,
    GREATER,
    GREATER_EQUAL,
    LESS,
    LESS_EQUAL,

    // Literals.
    IDENTIFIER,
    STRING,
    NUMBER,

    // Keywords.
    AND,
    CLASS,
    ELSE,
    FALSE,
    FUN,
    IF,
    NONE,
    OR,
    PRINT,
    RETURN,
    SUPER,
    THIS,
    TRUE,
    VAR,
    WHILE,

    EOF_TOKEN // Renamed from EOF to EOF_TOKEN to avoid conflict with std::EOF
};

class Token
{
public:
    TokenType type;
    std::string lexeme;
    std::variant<std::monostate, std::string, double> literal;
    int line;

    Token(TokenType type, const std::string &lexeme, const std::variant<std::monostate, std::string, double> &literal, int line)
        : type(type), lexeme(lexeme), literal(literal), line(line) {}

    std::string toString() const
    {
        std::string literalStr;
        if (std::holds_alternative<std::string>(literal))
        {
            literalStr = std::get<std::string>(literal);
        }
        else if (std::holds_alternative<double>(literal))
        {
            literalStr = std::to_string(std::get<double>(literal));
        }
        else
        {
            literalStr = "null";
        }
        return "Token(" + tokenTypeToString(type) + ", " + lexeme + ", " + literalStr + ", " + std::to_string(line) + ")";
    }

private:
    std::string tokenTypeToString(TokenType type) const
    {
        switch (type)
        {
        case LEFT_PAREN:
            return "LEFT_PAREN";
        case RIGHT_PAREN:
            return "RIGHT_PAREN";
        case LEFT_BRACE:
            return "LEFT_BRACE";
        case RIGHT_BRACE:
            return "RIGHT_BRACE";
        case COMMA:
            return "COMMA";
        case DOT:
            return "DOT";
        case MINUS:
            return "MINUS";
        case PLUS:
            return "PLUS";
        case SEMICOLON:
            return "SEMICOLON";
        case SLASH:
            return "SLASH";
        case STAR:
            return "STAR";
        case BANG:
            return "BANG";
        case BANG_EQUAL:
            return "BANG_EQUAL";
        case EQUAL:
            return "EQUAL";
        case EQUAL_EQUAL:
            return "EQUAL_EQUAL";
        case GREATER:
            return "GREATER";
        case GREATER_EQUAL:
            return "GREATER_EQUAL";
        case LESS:
            return "LESS";
        case LESS_EQUAL:
            return "LESS_EQUAL";
        case IDENTIFIER:
            return "IDENTIFIER";
        case STRING:
            return "STRING";
        case NUMBER:
            return "NUMBER";
        case AND:
            return "AND";
        case CLASS:
            return "CLASS";
        case ELSE:
            return "ELSE";
        case FALSE:
            return "FALSE";
        case FOR:
            return "FOR";
        case IF:
            return "IF";
        case NONE:
            return "NONE";
        case OR:
            return "OR";
        case PRINT:
            return "PRINT";
        case RETURN:
            return "RETURN";
        case SUPER:
            return "SUPER";
        case THIS:
            return "THIS";
        case TRUE:
            return "TRUE";
        case VAR:
            return "VAR";
        case WHILE:
            return "WHILE";
        case EOF_TOKEN:
            return "EOF";
        default:
            return "UNKNOWN";
        }
    }
};

class Lexer
{
private:
    bool errorPresent = false;

    void reportError(int line, string at, string message)
    {
        string messageOut = "{line " + to_string(line) + "} - Error" + at + ": " + message;
        cout << messageOut << endl;
        errorPresent = true;
    }

    void throwError(int line, string message)
    {
        reportError(line, "", message);
    }

public:
    string run(string file)
    {
        // DFA'S INSIDE DFA'S
        vector<pair<string, string>> line;
        // make_pair(,)

        if (errorPresent)
        {
            return ("!Error");
        }
    }
};

int main()
{
    Lexer lexer = Lexer();
    lexer.run("int a = 0; int b = a + 7;");
    return 0;
}
