#pragma once
#include <string>

using namespace std;

class Message
{
public:
    Message(const string& from, const string& to, const string& text) :
        _from(from),
        _to(to),
        _text(text)
    {}

    ~Message() {}

    const string& getFrom() const { return _from; }
    const string& getTo() const { return _to; }
    const string& getText() const { return _text; }
private:
    string _from;
    string _to;
    string _text;
};