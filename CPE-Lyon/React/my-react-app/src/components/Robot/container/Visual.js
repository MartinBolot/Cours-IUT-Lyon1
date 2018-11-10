import React, { Component } from 'react';

class Visual extends Component {
  render() {
    switch(this.props.type) {
      case "img": {
        return(
          <div className="thumbnail">
            <img
              alt=""
              className='imgCard'
              src={this.props.src}
            />
          </div>
        );
      }
      case "video": {
        return(
          <div className="thumbnail">
            {/*<video className='imgCard'>
              <source src={this.props.source}/>
            </video>*/}
            <iframe title={this.props.id} src={this.props.src} />
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
