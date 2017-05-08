#include <memory>
#include <string>

class FileReader;

class User;

class LoginController {
public:
    LoginController();
    std::shared_ptr<User> get_user(std::string);
private:
    std::shared_ptr<FileReader> reader;
};