#include "CreateSecretWidget.h"
#include <QPushButton>
#include <QVBoxLayout>

CreateSecretWidget::CreateSecretWidget(QWidget* parent) : QWidget(parent) {
    QLayout* layout = new QVBoxLayout(this);

    _message_input = new QLineEdit(this);
    layout->addWidget(_message_input);

    _secret_input = new QLineEdit(this);
    layout->addWidget(_secret_input);

    _result = new QLineEdit(this);
    _result->setReadOnly(true);
    layout->addWidget(_result);

    QSpacerItem* _spacer = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);
    layout->addItem(_spacer);

    QPushButton* _create_secret_button = new QPushButton("Create Secret", this);
    layout->addWidget(_create_secret_button);

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
    _result->setText(message+ " " + secret);
}
