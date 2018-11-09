import React, { Component } from 'react';

class Price extends Component {
  constructor(props) {
    super(props);
  }
  render() {
    return(
      <div className="btn btn-primary" type="button">
        Price <span className="badge">{this.props.value}</span>
      </div>
    );
  }
}

export default Price;
