class Settings {
public:
    static Settings& getInstance();

private:
    Settings();  // Private constructor to prevent instantiation
    Settings(const Settings&) = delete;  // Delete copy constructor
    Settings& operator=(const Settings&) = delete;  // Delete assignment operator
};
