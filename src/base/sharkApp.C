#include "sharkApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
sharkApp::validParams()
{
  InputParameters params = MooseApp::validParams();

  return params;
}

sharkApp::sharkApp(InputParameters parameters) : MooseApp(parameters)
{
  sharkApp::registerAll(_factory, _action_factory, _syntax);
}

sharkApp::~sharkApp() {}

void
sharkApp::registerAll(Factory & f, ActionFactory & af, Syntax & syntax)
{
  ModulesApp::registerAll(f, af, syntax);
  Registry::registerObjectsTo(f, {"sharkApp"});
  Registry::registerActionsTo(af, {"sharkApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
sharkApp::registerApps()
{
  registerApp(sharkApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
sharkApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  sharkApp::registerAll(f, af, s);
}
extern "C" void
sharkApp__registerApps()
{
  sharkApp::registerApps();
}
