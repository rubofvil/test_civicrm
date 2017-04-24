Test CiviCRM
============


## Necessary replace if you generate the test with civix
"extends CiviUnitTestCase {"
by
"extends PHPUnit_Framework_TestCase {"

## Necessary delete the next line if you generate the test with civix
require_once 'CiviTest/CiviUnitTestCase.php';
