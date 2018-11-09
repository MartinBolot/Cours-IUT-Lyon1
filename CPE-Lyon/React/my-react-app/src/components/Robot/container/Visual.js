import React, { Component } from 'react';

class Visual extends Component {
  constructor(props) {
    super(props);
  }
  render() {
    switch(this.props.type) {
      case "img": {
        return(
          <div className="thumbnail">
            <img className='imgCard' src={this.props.source} />
          </div>
        );
      }
      case "video": {
        return(
          <div className="thumbnail">
            {/*<video className='imgCard'>
              <source src={this.props.source}/>
            </video>*/}
            <iframe src={this.props.source} />
          </div>
      );
      }
      default: {
        return(<div></div>);
      }
    }
  }
}

export default Visual;
