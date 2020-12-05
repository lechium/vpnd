# vpnd
VPN daemon utilized by nitoTV to deliver VPN access on tvOS

This is normally built as part of nitoTV in an Xcode project, i didn't feel like re-creating the daemon like that as a part of a new xcode project because that is a pretty massive pain to do. 

Still need to add some companion code on how to interact with the VPN. nicely cleaned up and documented now at least.

Read more about [configuration profiles](https://developer.apple.com/business/documentation/Configuration-Profile-Reference.pdf)

I recommend creating profiles to experiment in [Apple Configurator 2](https://support.apple.com/apple-configurator)

***build and use at your own risk! working with NEVPNManager is a huge & finicky pain if you arent familiar with it.***
