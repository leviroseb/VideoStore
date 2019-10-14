#include <iostream>
#include <string>

using namespace std;

class videoType{
    friend ostream& operator << (ostream&, const videoType&);
public:
    videoType(string title = "", string star1 = "",string star2 = "",string producer = "",
              string director = "", string productionCo = "",int setInStock = 0);

    void setVideoInfo(string title, string star1,string star2, string producer,
                      string director, string productionCo,int setInStock);
    int getNoOfCopiesInStock() const;
    void checkOut();
    void checkIn();
    void printTitle() const;
    void printInfo() const;
    bool checkTitle(string title);
    void updateInStock(int num);
    void setCopiesInStock(int num);
    string getTitle() const;

    bool operator==(const videoType&) const;
    bool operator!=(const videoType&) const;
private:
    string videoTitle;
    string movieStar1;
    string movieStar2;
    string movieProducer;
    string movieDirector;
    string movieProductionCo;
    int copiesInStock;
};

videoType::videoType(string title, string star1,string star2, string producer,
                     string director, string productionCo, int setInStock){

    setVideoInfo(title, star1, star2, producer, director, productionCo, setInStock);
}

void videoType::setVideoInfo(string title, string star1,string star2, string producer,
                             string director, string productionCo, int setInStock){
    videoTitle = title;
    movieStar1 = star1;
    movieStar2 = star2;
    movieProducer = producer;
    movieDirector = director;
    movieProductionCo = productionCo;
    copiesInStock = setInStock;
}

void videoType::checkOut(){
    if (getNoOfCopiesInStock() > 0)
        copiesInStock--;
    else
        cout << "Currently out of stock" << endl;
}
void videoType::checkIn(){
    copiesInStock++;
}
int videoType::getNoOfCopiesInStock() const{
    return copiesInStock;
}
void videoType::printTitle() const{
    cout << "Titulo del Video: " << videoTitle << endl;
}
void videoType::printInfo() const{
    cout << "Titulo del Video: " << videoTitle << endl;
    cout << "Estrellas: " << movieStar1 << " and " << movieStar2 << endl;
    cout << "Productor: " << movieProducer << endl;
    cout << "Director: " << movieDirector << endl;
    cout << "Compania de Produccion: " << movieProductionCo << endl;
    cout << "Copias en Stock: " << copiesInStock << endl;
}
bool videoType::checkTitle(string title){
    return (videoTitle == title);
}
void videoType::updateInStock(int num){
    copiesInStock += num;
}
void videoType::setCopiesInStock(int num){
    copiesInStock = num;
}

string videoType::getTitle() const{
    return videoTitle;
}

bool videoType::operator==(const videoType& other) const{
    return (videoTitle == other.videoTitle);
}
bool videoType::operator!=(const videoType& other) const{
    return (videoTitle != other.videoTitle);
}
ostream& operator<< (ostream& osObject, const videoType& video){
    osObject << endl;
    osObject << "Video Title: " << video.videoTitle << endl;
    osObject << "Stars: " << video.movieStar1 << " and " << video.movieStar2 << endl;
    osObject << "Producer: " << video.movieProducer << endl;
    osObject << "Director: " << video.movieDirector << endl;
    osObject << "Production Company: " << video.movieProductionCo << endl;
    osObject << "Copies in stock: " << video.copiesInStock << endl;
    osObject << "_____________________________________" << endl;
    return osObject;
}

