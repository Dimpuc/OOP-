#include <iostream>
#include <vector>

// Абстрактний клас шахової фігури
class ChessPiece {
public:
    virtual void CanMoveTo(const std::string& currentPosition, const std::string& newPosition) const = 0;
};

// Клас пішака
class Pawn : public ChessPiece {
public:
    void CanMoveTo(const std::string& currentPosition, const std::string& newPosition) const override {
        // Логіка перевірки можливості ходу пішака
        std::cout << "Checking if pawn can move from " << currentPosition << " to " << newPosition << std::endl;
        // ...
    }
};

// Клас коня
class Knight : public ChessPiece {
public:
    void CanMoveTo(const std::string& currentPosition, const std::string& newPosition) const override {
        // Логіка перевірки можливості ходу коня
        std::cout << "Checking if knight can move from " << currentPosition << " to " << newPosition << std::endl;
        // ...
    }
};

// Інші класи шахових фігур

int main() {
    std::vector<ChessPiece*> chessPieces;
    
    // Додавання об'єктів різних класів у вектор
    chessPieces.push_back(new Pawn());
    chessPieces.push_back(new Knight());
    // Додаткові об'єкти інших шахових фігур
    
    // Перегляд елементів вектора через виклик поліморфної
    for (const auto& piece : chessPieces) {
        piece->CanMoveTo("e2", "e4");  // Виклик поліморфної функції для кожного об'єкта
    }

    // Видалення об'єктів з вектора і звільнення пам'яті
    for (const auto& piece : chessPieces) {
        delete piece;
    }
    chessPieces.clear();
    
    return 0;
}