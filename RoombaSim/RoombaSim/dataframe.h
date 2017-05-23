#ifndef DATAFRAME_H
#define DATAFRAME_H

#include <QByteArray>
#include <vector>

class Dataframe {
public:
    Dataframe() {}

    Dataframe(const std::vector<unsigned char>& data) {
        _data = setDataframe(data);
    }

    static QByteArray setDataframe(const std::vector<unsigned char>& data) {
        QByteArray d;

        d[0] = 19;
        d[1] = data.size();

        for(auto byte : data) {
            d.push_back(static_cast<char>(byte));
        }

        setChecksum(d);

        return d;
    }

    static void setChecksum(QByteArray& data) {
        int checksumValue{};

        for(int i = 0; i < data.at(1) + 2; i++){
            checksumValue += (int)data.at(i);
        }

        data[data.at(1) + 2] = 256 - checksumValue;
    }

    QByteArray data() const { return _data; }

private:
    QByteArray _data;
};

#endif // DATAFRAME_H
