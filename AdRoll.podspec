Pod::Spec.new do |s|
  s.name                = "AdRoll"
  s.version             = "1.1.3"
  s.summary             = "AdRoll iOS SDK."

  s.homepage            = "https://github.com/AdRoll"
  s.license             = "Copyright (c) 2014 AdRoll."
  s.author              = { "AdRoll" => "support@adroll.com" }
  s.source              = { :http => "https://github.com/AdRoll/adroll-ios.git" }
  s.social_media_url    = 'https://twitter.com/AdRoll'

  s.platform            = :ios, '6.0'
  s.requires_arc        = true

  s.source_files        = 'AdRoll.framework/Versions/1.1.3/Headers/{AdRoll,AdRoll+Advanced,AdRoll-Constants}.h'
  s.preserve_paths      = 'AdRoll.framework'
  s.vendored_frameworks = 'AdRoll.framework'

  s.libraries           = 'sqlite3'
  s.frameworks          = 'Security', 'AdSupport'

end
