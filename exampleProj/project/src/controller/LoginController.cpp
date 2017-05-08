#include "LoginController.hpp"
#include "User.hpp"
#include "FileReader.hpp"

LoginController::LoginController() : reader(std::shared_ptr<FileReader>(new FileReader("users.txt"))) {}

std::shared_ptr<User> LoginController::get_user(std::string login) {
    std::vector<std::shared_ptr<User>> users = reader->users();
    for (std::shared_ptr<User> user : users) {
        if (user->get_login() == login) {
            return user;
        }
    }
    return nullptr;
}