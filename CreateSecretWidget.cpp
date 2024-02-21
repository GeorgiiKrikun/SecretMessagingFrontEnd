#include "CreateSecretWidget.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QStyle>
#include "Encoder.h"
#include "qapplication.h"

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


    QWidget* _container = new QWidget(this);
    layout->addWidget(_container);
    QHBoxLayout* _container_layout = new QHBoxLayout(_container);

    _result = new QLineEdit(this);
    _result->setReadOnly(true);
    _result->setPlaceholderText("Here the secret string will appear");
    _container_layout->addWidget(_result);

    QPushButton* _copy_button = new QPushButton("", this);
    QIcon openIcon = QApplication::style()->standardIcon(QStyle::SP_DriveFDIcon);
    _copy_button->setIcon(openIcon);
    _container_layout->addWidget(_copy_button);


    QSpacerItem* _spacer = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);
    layout->addItem(_spacer);

    QObject::connect(_copy_button,
                     & QPushButton::clicked,
                     this,
                     & CreateSecretWidget::copySecret,
                     Qt::DirectConnection);

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

void CreateSecretWidget::copySecret()
{
    _result->selectAll();
    _result->copy();
    _result->deselect();
}
