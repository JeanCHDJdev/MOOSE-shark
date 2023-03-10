//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "sharkTestApp.h"
#include "sharkApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

InputParameters
sharkTestApp::validParams()
{
  InputParameters params = sharkApp::validParams();
  return params;
}

sharkTestApp::sharkTestApp(InputParameters parameters) : MooseApp(parameters)
{
  sharkTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

sharkTestApp::~sharkTestApp() {}

void
sharkTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  sharkApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"sharkTestApp"});
    Registry::registerActionsTo(af, {"sharkTestApp"});
  }
}

void
sharkTestApp::registerApps()
{
  registerApp(sharkApp);
  registerApp(sharkTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
sharkTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  sharkTestApp::registerAll(f, af, s);
}
extern "C" void
sharkTestApp__registerApps()
{
  sharkTestApp::registerApps();
}
