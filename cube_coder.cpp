#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

class CubeEncoder{
private:
    vector<vector<char>> cube;
    int size {0};
public:
    enum class Coder{
        none, right, left, up, down, x
    };
private:
    int find_size(int size) const{
        int n {0};
        while (n * n < size){
            ++n;
        }
        return n;
    }

    void fill_cube(const string& original_text){
        cube.resize(size, vector<char>(size, ' '));
        for(int i = 0; i < original_text.size(); ++i){
            cube[i / size][i % size] = original_text[i];
        }
        
    }

    string right_encode() {
    for (int i = 0; i < size; ++i) {
        char last = cube[i][size - 1];
        
        for (int j = size - 1; j > 0; --j) {
            cube[i][j] = cube[i][j - 1];
        }
        
        cube[i][0] = last;
    }

    return final_string();
}

    string left_encode(){
        for (int i = 0; i < size; ++i) {
            char first = cube[i][0];
        
            for (int j = 0; j < size - 1; ++j) {
                cube[i][j] = cube[i][j + 1];
            }
        
            cube[i][size - 1] = first;
        }

        return final_string();
    }

    string up_encode(){
        vector<char> first_row = cube[0];
    
        for (int i = 0; i < size - 1; ++i) {
            cube[i] = cube[i + 1];
        }
        
        cube[size - 1] = first_row;
        return final_string();
    }

    string down_encode(){
        vector<char> last_row = cube[size - 1];
    
        for (int i = size - 1; i > 0; --i) {
        cube[i] = cube[i - 1];
        }
    
        cube[0] = last_row;
        return final_string();
    }
    
    string x_encode() {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if (i + j == size - 1 && i < j) {
                    std::swap(cube[i][j], cube[j][i]);
                }
            }
        }

    return final_string();
}

    inline string right_decode(){ return left_encode(); }

    inline string left_decode() { return right_encode(); }

    inline string up_decode(){ return down_encode(); }

    inline string down_decode(){ return up_encode(); }
    
    string final_string(){
        string result;
        for (const auto& row : cube) {
            for (char ch : row) {
                result += ch;
            }
        }
        return result;
    }

public:
    CubeEncoder() = delete;
    CubeEncoder(const string& text){
        size = find_size(text.size());
        fill_cube(text);
    }

    CubeEncoder& operator=(const string& other){
        size = find_size(other.size());
        fill_cube(other);  
        return *this;  
    }
     
    string encode(Coder type = Coder::none){
        switch(type){
            case Coder::right: return right_encode(); 
            case Coder::left: return left_encode(); 
            case Coder::up: return up_encode(); 
            case Coder::down: return down_encode(); 
            case Coder::x: return x_encode(); 
            default:
                cout << "Wrong encoding choice! Possible options:(prefix: CubeEncoder::Coder::)\n1) right\n2) left\n3) up\n4) down\n5) x" << endl;
                exit(1);
        }
    }

    string decode(Coder type = Coder::none){
        switch(type){
            case Coder::right: return right_decode(); 
            case Coder::left: return left_decode(); 
            case Coder::up: return up_decode(); 
            case Coder::down: return down_decode(); 
            case Coder::x: return x_encode(); 
            default:
                cout << "Wrong decoding choice! Possible options:(prefix: CubeEncoder::Coder::)\n1) right\n2) left\n3) up\n4) down\n5) x" << endl;
                exit(1);
        }
    }
};

int main(){
    CubeEncoder encoder("Hovhannes Kharazyan");
    encoder = encoder.encode(CubeEncoder::Coder::right);
    string encoded = encoder.encode(CubeEncoder::Coder::x);    
    cout << "Encoded: " << encoded << endl;
    encoder = encoded;
    encoder = encoder.decode(CubeEncoder::Coder::x);
    encoded = encoder.decode(CubeEncoder::Coder::right);
    cout << "Decoded: " << encoded << endl;
}
