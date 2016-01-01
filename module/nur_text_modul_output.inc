<?php
$editor                 = 0;
if(!rex_addon::get('rex_redactor')->isAvailable() AND !rex_addon::get('rex_markitup')->isAvailable()) {
    echo rex_view::error('Dieses Modul ben&ouml;tigt das "Redactor" oder das "MarkItUp" Addon!');
}
if(rex_addon::get('rex_redactor')->isAvailable()) {
  $editor = 'redactor';
 }
if(rex_addon::get('rex_markitup')->isAvailable()) {
  $editor = 'markitup';
}

$text             = 'REX_VALUE[1]';

if ($text !='') {
  if ($editor == 'markitup' AND rex_addon::get('textile')->isAvailable()) {
    $text = str_replace('<br />', '', $text);
    $text = rex_textile::parse($text);
  }
}

$text = '<div class="text">'.$text.'</div>'.PHP_EOL;


if(!rex::isBackend()) {

echo $text;

} else {
 echo '
  <div id="nurtext" class="bereichswrapper">
    <div class="form-horizontal output">
     <h2 class="ueberschrift" >Nur Text</h2>
       <div class="form-group">
         <label class="col-sm-3 control-label">Nur Text</label>
         <div class="col-sm-9">'.$text.'</div>
       </div>
    </div>
  </div>

<style>
#nurtext .bereichswrapper {
  margin: 5px 0 5px 0;
  background: #f5f5f5;
  padding: 5px 15px 5px 15px;
  border: 1px solid #9da6b2;
}

#nurtext .control-label {
  font-weight: normal;
  font-size: 12px;
  margin-top: -6px;
}

#nurtext  h2.ueberschrift {
  font-size: 12px !important;
  padding: 0 10px 10px 10px;
  margin-bottom: 15px;
  width: 100%;
  font-weight: bold;
  border-bottom: 1px solid #31404F;
}

</style>'.PHP_EOL;
}