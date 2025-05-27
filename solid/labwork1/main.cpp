#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class ICounter {
public:
    virtual void count(std::istream& in) = 0;
    virtual void printResult() const = 0;
    virtual ~ICounter() {}
};

class LineCounter : public ICounter {
private:
    unsigned long long lines;
public:
    LineCounter() : lines(0) {}

    void count(std::istream& in) override {
        lines = 0;
        std::string line;
        while (std::getline(in, line)) {
            lines++;
        }
    }

    void printResult() const override {
        std::cout << "Lines: " << lines << std::endl;
    }
};

class WordCounter : public ICounter {
private:
    unsigned long long words;
public:
    WordCounter() : words(0) {}

    void count(std::istream& in) override {
        words = 0;
        std::string word;
        while (in >> word) {
            words++;
        }
    }

    void printResult() const override {
        std::cout << "Words: " << words << std::endl;
    }
};

class ByteCounter : public ICounter {
private:
    unsigned long long bytes;
public:
    ByteCounter() : bytes(0) {}

    void count(std::istream& in) override {
        bytes = 0;
        char c;
        while (in.get(c)) {
            bytes++;
        }
    }

    void printResult() const override {
        std::cout << "Bytes: " << bytes << std::endl;
    }
};

class CharCounter : public ICounter {
private:
    unsigned long long chars;
public:
    CharCounter() : chars(0) {}

    void count(std::istream& in) override {
        chars = 0;
        char c;
        while (in.get(c)) {
            chars++;
        }
    }

    void printResult() const override {
        std::cout << "Characters: " << chars << std::endl;
    }
};

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " [-l] [-w] [-b] [-c] <filename>" << std::endl;
        return 1;
    }

    std::string filename = argv[argc - 1];
    if (!filename.empty() && filename[0] == '-') {
        std::cerr << "Error: filename is missing." << std::endl;
        std::cerr << "Usage: " << argv[0] << " [-l] [-w] [-b] [-c] <filename>" << std::endl;
        return 1;
    }

    bool flagL = false, flagW = false, flagB = false, flagC = false;
    for (int i = 1; i < argc - 1; ++i) {
        if (argv[i][0] == '-') {
            for (int j = 1; argv[i][j] != '\0'; ++j) {
                char f = argv[i][j];
                if (f == 'l') {
                    flagL = true;
                } else if (f == 'w') {
                    flagW = true;
                } else if (f == 'b') {
                    flagB = true;
                } else if (f == 'c') {
                    flagC = true;
                } else {
                    std::cerr << "Unknown flag: -" << f << std::endl;
                    std::cerr << "Usage: " << argv[0] << " [-l] [-w] [-b] [-c] <filename>" << std::endl;
                    return 1;
                }
            }
        } else {
            std::cerr << "Unexpected argument: " << argv[i] << std::endl;
            std::cerr << "Usage: " << argv[0] << " [-l] [-w] [-b] [-c] <filename>" << std::endl;
            return 1;
        }
    }

    if (!flagL && !flagW && !flagB && !flagC) {
        flagL = flagW = flagB = flagC = true;
    }

    std::ifstream testFile(filename);
    if (!testFile) {
        std::cerr << "Error: cannot open file " << filename << std::endl;
        return 1;
    }
    testFile.close();

    std::vector<ICounter*> counters;
    if (flagL) {
        counters.push_back(new LineCounter());
    }
    if (flagW) {
        counters.push_back(new WordCounter());
    }
    if (flagB) {
        counters.push_back(new ByteCounter());
    }
    if (flagC) {
        counters.push_back(new CharCounter());
    }

    for (ICounter* counter : counters) {
        std::ifstream inFile(filename, std::ios::binary);
        inFile.seekg(0);
        counter->count(inFile);
        inFile.close();
    }

    for (ICounter* counter : counters) {
        counter->printResult();
    }

    for (ICounter* counter : counters) {
        delete counter;
    }
    counters.clear();

    return 0;
}
