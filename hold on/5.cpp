//StudybarCommentBegin
#include <iostream>
#include <string>
using namespace std;

class GameCharacter {
public:

    GameCharacter( std::string name ) : HealthValue(10),m_name( name ) {
    }

    int BeHitted( ) {
        int v= this->ChangeHealthValue( );
        if(v <=0)  cout<<endl<<GetName( )<<"is dead";
        return v;
    }
    int GetHealthValue() const {return this->HealthValue;}
    std::string GetName( ) const {
        return m_name;
    }

protected:

    virtual int ChangeHealthValue( ) =0;
    int HealthValue;
    std::string m_name;
};
//StudybarCommentEnd

class Player : public GameCharacter {
public:
    Player(std::string name) : GameCharacter(name) {}
protected:
    virtual int ChangeHealthValue() {
        HealthValue -= 1;
        return HealthValue;
    }
};

class Monster : public GameCharacter {
public:
    Monster(std::string name) : GameCharacter(name) {}
protected:
    virtual int ChangeHealthValue() {
        HealthValue -= 2;
        return HealthValue;
    }
};

//StudybarCommentBegin
int main( ) {
    Player p( "Player" );
    Monster m( "Monster" );

    p.BeHitted();
    m.BeHitted();

    std::cout << p.GetName( ) << ": " << p.GetHealthValue() << std::endl;
    std::cout << m.GetName( ) << ": " << m.GetHealthValue() << std::endl;

    return 0;
}
//StudybarCommentEnd