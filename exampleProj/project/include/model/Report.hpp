#include <vector>
#include <memory>

class Transaction;

// Report contains related transaction and summary
class Report {
public:

    // Summary stores total income, total outcome and delta (difference: income - outcome)
    class Summary {
    public:
        Summary(int income, int outcome, int delta);
        int get_delta() const;
        int get_income() const;
        int get_outcome() const;
    private:
        int delta;
        int income;
        int outcome;
    };

    Report(std::vector<std::shared_ptr<Transaction>> transactions, Summary summary);

    Summary get_summary() const;
    const std::vector<std::shared_ptr<Transaction>> & get_transactions() const;

private:
    std::vector<std::shared_ptr<Transaction>> transactions;
    Summary summary;
};