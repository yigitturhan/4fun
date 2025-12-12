#ifndef CONFIG_H
#define CONFIG_H

#include <string>

class Config {
public:
    bool load(const std::string& path);
    bool save(const std::string& path) const;

    int getDAS() const;
    int getARR() const;

private:
    int das;
    int arr;
};

#endif
