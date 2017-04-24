<?php

require_once("libraries/autoload.php");

/**
 * Implements hook_drush_command().
 */
function test_civicrm_drush_command() {

  $commands['test-civicrm'] = [
    'description' => 'This is my example command.',
    'aliases' => ['tc'],    
     'options' => [
       'class' => 'Class to execute.',
     ],
     'examples' => [
       'drush tc' => 'Print my example command.',       
     ],
  ];

  return $commands;
}

/**
 * Drush command logic.
 * drush_[MODULE_NAME]_[COMMAND_NAME]().
 */
function drush_test_civicrm() {
  $class_to_execute = drush_get_option('class', 'All');
  civicrm_initialize();
  global $civicrm_root;
  if (empty($civicrm_root) || !is_dir($civicrm_root)) {
   echo "Error getting global CiviCRM root";
   return;
  }
  $config =CRM_Core_Config::singleton( );  
  
  $extensions_dir = $config->extensionsDir;      
  $configAndLogDir = $config->configAndLogDir;  
  
  $directories_to_seach = array(
    $extensions_dir,
    $configAndLogDir    
  );
  
  foreach ($directories as $directory) {
    foreach(rglob($directory. "/*PHPUNITTest.php")  as $file) {    
      $command = new PHPUnit_TextUI_Command;
      $command->run(array('phpunit', '--log-junit', 'results.xml', $file), true);        
    }
  }
  
    
  
}

// Does not support flag GLOB_BRACE
function rglob($pattern, $flags = 0) {
  $files = glob($pattern, $flags); 
  foreach (glob(dirname($pattern).'/*', GLOB_ONLYDIR|GLOB_NOSORT) as $dir) {
    $files = array_merge($files, rglob($dir.'/'.basename($pattern), $flags));
  }
  return $files;
}
