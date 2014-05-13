#include "character_creator.h"
#include "ui_character_creator_dialog.h"
#include "widget_manager.h"

CharacterCreator::CharacterCreator(QWidget* parent /*= 0*/)
    : QWizard(parent)
{
    _ui = new Ui::CharacterCreator;
    _ui->setupUi(this);
    _createRequest = new Protocol::CSCreateCharacterReq;

    addPage(WidgetManager::getInstance().characterCreator_IntrodutionPage());
    addPage(WidgetManager::getInstance().characterCreator_BaseInfoPage());
    addPage(WidgetManager::getInstance().characterCreator_CareerBeliefPage());
    addPage(WidgetManager::getInstance().characterCreator_CharacteristicPage());
    addPage(WidgetManager::getInstance().characterCreator_EpicPage());
    addPage(WidgetManager::getInstance().characterCreator_SummaryPage());

    setButtonText(QWizard::BackButton, QStringLiteral("上一步"));
    setButtonText(QWizard::NextButton, QStringLiteral("下一步"));
    setButtonText(QWizard::CancelButton, QStringLiteral("返回登录界面"));
    setButtonText(QWizard::FinishButton, QStringLiteral("完成创建"));
}

CharacterCreator::~CharacterCreator()
{
    delete _createRequest;
    delete _ui;
}

bool CharacterCreator::validateCurrentPage()
{
    if (this->page(this->nextId())->isFinalPage())
    {
        WidgetManager::getInstance().characterCreator_SummaryPage()->updateDescriptions();
    }

    return currentPage()->validatePage();
}
/*
int CharacterCreator::nextId() const
{
    return 0;
}
*/
