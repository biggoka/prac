#include <memory>
#include <string>
#include <vector>

class Transaction;
class User;

class FileReader{
public:
    FileReader(std::string filename);
    std::vector<std::shared_ptr<Transaction>> transactions() const;
    std::vector<std::shared_ptr<User>> users() const;
private:
    std::string filename;
};