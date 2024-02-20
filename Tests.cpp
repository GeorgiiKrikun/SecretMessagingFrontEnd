#include "Tests.h"
#include "Encoder.h"
#include <iostream>


bool test_encode_decode_ascii()  {
    QString data = "Hello, World!";
    QString encoded = encoder::encode(data);
    QString decoded = encoder::decode(encoded);
    // std::cout << "Original: " << data.toStdString() << std::endl;
    // std::cout << "Encoded: " << encoded.toStdString() << std::endl;
    // std::cout << "Decoded: " << decoded.toStdString() << std::endl;
    return data == decoded;
}

bool test_encode_decode_other()  {
    QString data = "ДАРОВА БРАТВА!";
    QString encoded = encoder::encode(data);
    QString decoded = encoder::decode(encoded);
    // std::cout << "Original: " << data.toStdString() << std::endl;
    // std::cout << "Encoded: " << encoded.toStdString() << std::endl;
    // std::cout << "Decoded: " << decoded.toStdString() << std::endl;
    return data == decoded;
}

bool test_combined_text_and_secret(QString message, QString secret) {
    QString encoded_message = encoder::encode(secret);
    QString result = encoded_message + message;
    QString decoded_message = encoder::decode(
        encoder::remove_unnecessary_symbols(result));
    return secret == decoded_message;
}

bool test_full_pipeline(QString message, QString secret) {
    QString encoded_message = encoder::mix_text_and_secret(message, secret);
    QString extracted_secret = encoder::extract_secret(encoded_message);
    return secret == extracted_secret;
}

int main(int argc, char *argv[])
{
    bool suc = true;
    suc = suc && test_encode_decode_ascii();
    suc = suc && test_encode_decode_other();
    suc = suc && test_combined_text_and_secret("Hello, World!", "secret");
    suc = suc && test_combined_text_and_secret("ДАРОВА БРАТВА!", "секрет");
    suc = suc && test_full_pipeline("Hello, World!", "secret");
    suc = suc && test_full_pipeline("ДАРОВА БРАТВА!", "секрет");

    if (suc) return 0;
    else return 1;
}

