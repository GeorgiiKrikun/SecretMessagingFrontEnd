#include "CreateSecretWidget.h"
#include <QPushButton>
#include <QVBoxLayout>
#include "Encoder.h"

CreateSecretWidget::CreateSecretWidget(QWidget* parent) : QFrame(parent) {
    QLayout* layout = new QVBoxLayout(this);
    setFrameStyle(QFrame::Box);
    _message_input = new QLineEdit(this);
    _message_input->setPlaceholderText("Enter the public message here ...");
    layout->addWidget(_message_input);

    _secret_input = new QLineEdit(this);
    _secret_input->setPlaceholderText("And the secret here ...");
    layout->addWidget(_secret_input);

    QPushButton* _create_secret_button = new QPushButton("Create Secret", this);
    layout->addWidget(_create_secret_button);

    _result = new QLineEdit(this);
    _result->setReadOnly(true);
    _result->setPlaceholderText("Here the secret string will appear");
    layout->addWidget(_result);



    QSpacerItem* _spacer = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);
    layout->addItem(_spacer);



    QObject::connect(_create_secret_button,
                     & QPushButton::clicked,
                     this,
                     & CreateSecretWidget::createSecret,
                     Qt::DirectConnection);
}

void CreateSecretWidget::createSecret()
{
    QString message = _message_input->text();
    QString secret = _secret_input->text();
    QString encoded_message = encoder::mix_text_and_secret(message,secret);
    _result->setText(encoded_message);
}
