#include <iostream>
#include <vector>
using namespace std;


class Handler {
public:
    virtual Handler* SetNext(Handler* handler) = 0;
    virtual std::string Handle(std::string request) = 0;
};

class AbstractHandler : public Handler {

private:
    Handler* next_handler_;

public:
    AbstractHandler() : next_handler_(nullptr) {
    }
    Handler* SetNext(Handler* handler) override {
        this->next_handler_ = handler;
        return handler;
    }
    std::string Handle(std::string request) override {
        if (this->next_handler_) {
            return this->next_handler_->Handle(request);
        }

        return {};
    }
};

class emailHandler : public AbstractHandler {
public:
    std::string Handle(std::string request) override {
        if (request == "me@gmail.com") {
            return "An email was sent to " + request + " address.\n";;
        }
        else {
            return AbstractHandler::Handle(request);
        }
    }
};
class phoneHandler : public AbstractHandler {
public:
    std::string Handle(std::string request) override {
        if (request == "099656565") {
            return "An SMS was sent to " + request + " number.\n";
        }
        else {
            return AbstractHandler::Handle(request);
        }
    }
};
class instaHandler : public AbstractHandler {
public:
    std::string Handle(std::string request) override {
        if (request == "@myinsta") {
            return "A access request was sent to " + request + " account.\n";
        }
        else {
            return AbstractHandler::Handle(request);
        }
    }
};


int main() {
    emailHandler* h1 = new emailHandler;
    phoneHandler* h2 = new phoneHandler;
    instaHandler* h3 = new instaHandler;
    // our chain is Email -> Phone -> Instagram
    h1->SetNext(h2)->SetNext(h3);

    std::string info;
    while (cin >> info) {
        if (info.compare("exit") == 0)
            break;
        const std::string result = h1->Handle(info);
        if (!result.empty()) {
            std::cout << "  " << result;
        }
        else {
            std::cout << "  " << info << " is not a valid login information.\n";
        }
    }


    delete h1;
    delete h2;
    delete h3;

    return 0;
}