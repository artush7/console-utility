
#include "main.hpp"

std::string to_lower(const std::string& s) 
{
    std::string result = s;
    std::transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

std::string sort_line(const std::string& line)
{
    std::istringstream iss(line);
    std::vector<std::string> words;
    std::string word;

    while (iss >> word)
    {
        words.push_back(word);
    }

    std::sort(words.begin(), words.end(), [](const std::string& a, const std::string& b) 
    {
        return to_lower(a) < to_lower(b);
    });
    
    
    std::string result;
    for (auto i = 0; i < words.size(); ++i) 
    {
        if (i > 0) 
        {
            result += " ";
        }
        result += words[i];
    }
    return result;

}

int main(int argc, char** argv)
{
    std::ifstream infile(argv[1]);
    std::ofstream outfile(argv[2]);

    if (infile.fail() || outfile.fail())
    {
        throw std::runtime_error("Error opening files");
    }

    std::string line;
    while (std::getline(infile, line))
    {
        outfile << sort_line(line) << "\n";
    }
    return 0;
}